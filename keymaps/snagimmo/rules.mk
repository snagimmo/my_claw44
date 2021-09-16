OLED_ENABLE = yes
OLED_DRIVER = SSD1306
OLED_GAMING = yes
LTO_ENABLE = yes

ifeq ($(strip $(OLED_ENABLE)), yes)
  SRC += font_block.c
endif

ifeq ($(strip $(OLED_GAMING)), yes)
  SRC += game/game.c
  SRC += game/drawing.c
  SRC += game/rndgen.c
endif
