OLED_DRIVER_ENABLE = yes

ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
  SRC += font_block.c
endif
