import os,sys,pygame

filepath = "sensorx.log"
filepath = filepath.replace('x', sys.argv[1])
file = open(filepath, 'r')

voltage_min = 0.4
voltage_max = 0.5 + (2 - int(sys.argv[1]))*0.05

pygame.init()
pygame.font.init()
font = pygame.font.SysFont('Comic Sans MS', 20)

width = 1600
height = 600
screen = pygame.display.set_mode((width,height))

green = (0, 255, 0)
red = (255, 0, 0)

done = False

for no_of_points,l in enumerate(file):
    l = l.split()
    if len(l) > 3:
        max_time = l[1]
    if no_of_points == 2:
        min_time = max_time.replace('00:00:','').replace(']','').replace('.0','')
    pass

max_time = max_time.replace('00:00:','').replace(']','').replace('.0','')

min_time = int(min_time)
time_diff = int(max_time) - min_time

no_of_points /= 3
no_of_points += 1
file.seek(0)

print("Number of readings: ",no_of_points)

print("CHECKING voltage between ", voltage_min, " and ", voltage_max)
while not done:
        for event in pygame.event.get():
                if event.type == pygame.QUIT:
                        done = True

        i = 0
        previous_voltage = 0
        previous_time = 0
        for line in file.readlines():
            line = line.split()
            time = line[1]
            if len(line) > 3:
                i += 1
                voltage = int(line[4], 16)/200
                time = time.replace('00:00:','').replace(']','').replace('.0','')
                time = int(time) - min_time
                bad_zone_diff = voltage_max - voltage_min
                voltage_diff = voltage - voltage_min - bad_zone_diff/2
                if i > 1:
                    pygame.draw.line(screen, (255,255,255), (width*previous_time/time_diff, height*(1 - previous_voltage)), (width*time/time_diff, height*(1 - voltage)), 1)
                previous_voltage = voltage
                previous_time = time
                pygame.draw.rect(screen, (155,155,155), pygame.Rect(width*time/time_diff, height*(1 - voltage), 5, 5))

        for j in range(1,10):
            pygame.draw.line(screen, (255,255,255), (0,height*(1 - j/10)), (10,height*(1 - j/10)), 3)
            
        pygame.draw.line(screen, (255,0,0), (0,height*(1 - voltage_min)), (width,height*(1 - voltage_min)), 2)
        textsurface = font.render(str(voltage_min), False, (255,255,255))
        screen.blit(textsurface, (0, height*(1 - voltage_min) - 5))
        pygame.draw.line(screen, (255,0,0), (0,height*(1 - voltage_max)), (width,height*(1 - voltage_max)), 2)
        textsurface = font.render(str(voltage_max), False, (255,255,255))
        screen.blit(textsurface, (0, height*(1 - voltage_max) - 5))
        
        pygame.display.flip()    
