OLED_ENABLE = yes
OLED_DRIVER = SSD1306

ifeq ($(strip $(OLED_ENABLE)), yes)
  SRC += font_block.c
endif
