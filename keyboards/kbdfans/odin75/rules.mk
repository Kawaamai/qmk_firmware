OLED_DRIVER = custom
# Project specific files
SRC += lib/ssd1306_sh1106.c
QUANTUM_LIB_SRC += spi_master.c
SRC += lib/bongocat.c

LTO_ENABLE = yes
DEBOUNCE_TYPE = asym_eager_defer_pk
KEY_OVERRIDE_ENABLE = yes
