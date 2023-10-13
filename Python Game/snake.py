import pygame
import sys
import random

screen_x = 600
screen_y = 600

class Snake(object):
    def __init__(self):
        self.dirction = pygame.K_RIGHT
        self.body = []
        for x in range(5):
            self.addnode()

    def addnode(self):
        left, top = (0,0)
        if self.body:
            left, top = (self.body[0].left, self.body[0].top)
        node = pygame.Rect(left, top, 25, 25)
        if self.dirction == pygame.K_LEFT:
            node.left -= 25
        elif self.dirction == pygame.K_RIGHT:
            node.left += 25
        elif self.dirction == pygame.K_UP:
            node.top -= 25
        elif self.dirction == pygame.K_DOWN:
            node.top += 25
        self.body.insert(0, node)

    def delnode(self):
        self.body.pop()

    def isdead(self):
        if self.body[0].x not in range(screen_x):
            return True
        if self.body[0].y not in range(screen_y):
            return True
        if self.body[0] in self.body[1:]:
            return True
        return False

    def move(self):
        self.addnode()
        self.delnode()

    def changedirection(self,key):
        LR = [pygame.K_LEFT, pygame.K_RIGHT]
        UD = [pygame.K_UP, pygame.K_DOWN]
        if key in LR + UD:
            if (key in LR) and (self.dirction in LR):
                return
            if (key in UD) and (self.dirction in UD):
                return
            self.dirction = key

class Food:
    def __init__(self):
        self.rect = pygame.Rect(-25, 0, 25, 25)

    def remove(self):
        self.rect.x = -25

    def set(self):
        if self.rect.x == -25:
            allpos = []
            for pos in range(25, screen_x - 25, 25):
                allpos.append(pos)
            self.rect.left = random.choice(allpos)
            self.rect.top = random.choice(allpos)
            print(self.rect)

def show_text(screen, pos, text, color, font_bold = False, font_size = 60, font_italic = False):
    cur_font = pygame.font.SysFont('宋体',font_size)
    cur_font.set_bold(font_bold)
    cur_font.set_italic(font_italic)
    text_fmt = cur_font.render(text,1,color)
    screen.blit(text_fmt,pos)






def main():
    pygame.init()
    screen_size = (screen_x, screen_y)
    screen = pygame.display.set_mode(screen_size)
    pygame.display.set_caption('snake')
    clock = pygame.time.Clock()
    scores = 0
    isdead = False


    snake = Snake()
    food = Food()

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()
            if event.type ==pygame.KEYDOWN:
                snake.changedirection(event.key)
                if event.key == pygame.K_SPACE and isdead:
                    return main()
        screen.fill((255,255,255))

        if not isdead:
            snake.move()
        for rect in snake.body:
            pygame.draw.rect(screen, (20,200,30), rect, 0)

        isdead = snake.isdead()

        if isdead:
            show_text(screen, (100,200), 'Game Over', (227,30,19), False, 100)
            show_text(screen, (100,200), 'press space to try again..', (0,0,22), False, 30)

        if food.rect == snake.body[0]:
            scores += 50
            food.remove()
            snake.addnode()

        food.set()
        pygame.draw.rect(screen, (136,0,24), food.rect, 0)

        show_text(screen, (50, 500), 'Scores:' + str(scores), (223,223,223))

        pygame.display.update()
        clock.tick(10)
        
        
main()
