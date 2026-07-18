import pygame
from sys import exit
pygame.init()

size=width,height=620,540
speed=[1,1]
black=0,0,0

screen=pygame.display.set_mode(size)

ball=pygame.image.load("TBALL.png")
ballrect=ball.get_rect()

x=pygame.mixer.Sound("tennisball-44184.mp3")

while True:
    for event in pygame.event.get():
        if event.type==pygame.QUIT: exit()

    ballrect=ballrect.move(speed)
    if ballrect.left < 0 or ballrect.right > width:
        x.play()
        speed[0] = -speed[0]

    if ballrect.top < 0 or ballrect.bottom > height:
        x.play()
        speed[1] = -speed[1]

    screen.fill(black)
    screen.blit(ball,ballrect)
    pygame.display.flip()

