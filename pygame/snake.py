import pygame
import random
x=pygame.init() # initializes each of these modules
#colors
white=(255,255,255)
red=(255,0,0)
green=(0,255,0)

gameDisplay=pygame.display.set_mode((900,600)) #create a graphical window
pygame.display.set_caption("SNAKE'S VALLEY")

clock = pygame.time.Clock()  # create an object to help track time
font = pygame.font.SysFont("comicsans", 30)

def text_screen(text,color,x,y):
    screen_text=font.render(text,True,color)
    gameDisplay.blit(screen_text,(x,y))

def plot_snake(game_Display,color,snk_list,snake_size):
    for x,y in snk_list:
        pygame.draw.rect(gameDisplay,color, (x,y, snake_size, snake_size))  # create rectangle


#Creating a game loop
def gameloop():
    # Game specific variables
    exit_game = False
    game_over = False
    snake_x = 50
    snake_y = 50
    velocity_x = 0
    velocity_y = 0
    init_velocity = 5

    snake_size = 20
    fps = 30
    score = 0

    food_x = random.randint(20, 450)
    food_y = random.randint(20, 300)

    snk_list = []
    snk_length = 1

    with open("highscore.txt","r") as f:
        highscore = int(f.read())

    p=pygame.mixer.Sound("pow-90398.mp3")
    q=pygame.mixer.Sound("game-character-140506.mp3")
    r=pygame.mixer.Sound("welcomestranger-34421 (mp3cut.net).mp3")
    hiss=pygame.mixer.Sound("snake-hiss.mp3")
    r.play()
    hiss.play()

    while not exit_game:
        if game_over:
            with open("highscore.txt","w") as f:
                f.write(str(highscore))
            gameDisplay.fill(white)
            q.play()
            text_screen("Game Over! Press Enter to continue",red,200,200)
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    exit_game = True
                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_RETURN:
                        gameloop()
        else:
            for event in pygame.event.get():#contains all the events,get events from the queue
                if event.type==pygame.QUIT:
                    exit_game=True
                if event.type==pygame.KEYDOWN: #detecting the keys pressed
                    if event.key==pygame.K_LEFT:
                        velocity_x=-init_velocity
                        velocity_y=0
                    if event.key==pygame.K_RIGHT:
                        velocity_x=init_velocity
                        velocity_y=0
                    if event.key==pygame.K_UP:
                        velocity_y=-init_velocity
                        velocity_x=0
                    if event.key==pygame.K_DOWN:
                        velocity_y=init_velocity
                        velocity_x=0
            snake_x+=velocity_x
            snake_y+=velocity_y

            if abs(snake_x-food_x)<6 and abs(snake_y-food_y)<6:
                score+=1
                init_velocity+=1
                p.play()
                food_x = random.randint(20, 450)
                food_y = random.randint(20, 300)
                snk_length+=5
                if score>int(highscore):
                    highscore=score

            if snake_x<0 or snake_y>600 or snake_y<0 or snake_x>900:
                game_over=True


            gameDisplay.fill(white)
            text_screen("Score: "+str(score)+ " Highscore: "+str(highscore),red,5,5)
            pygame.draw.rect(gameDisplay,red,(food_x,food_y,snake_size,snake_size))

            head=[]
            head.append(snake_x)
            head.append(snake_y)
            snk_list.append(head)

            if len(snk_list)>snk_length:
                del snk_list[0]
            if head in snk_list[:-1]:
                game_over=True


            plot_snake(gameDisplay,green,snk_list,snake_size)
        pygame.display.update()
        clock.tick(fps)


    pygame.quit()
    quit()
gameloop()
