OLED_DRIVER_ENABLE = yes
OLED_GAMING = yes

ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
  SRC += font_block.c
endif

ifeq ($(strip $(OLED_GAMING)), yes)
  SRC += game/game.c
  SRC += game/drawing.c
  SRC += game/rndgen.c
endif
