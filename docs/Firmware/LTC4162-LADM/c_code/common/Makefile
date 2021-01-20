
HEADERS = LTC4162-LADM.h LTC4162-LADM_reg_defs.h LTC4162-LADM_formats.h LTC4162-LADM_pec.h
ifeq ($(OS),Windows_NT)
	TARGETEXT := .exe
	#RM := del
	RM := rm -f
else
	TARGETEXT := 
	RM := rm -f
endif
CC := gcc
CFLAGS := -Wall -Wextra -Wpedantic
CFLAGS += -std=c99
#CFLAGS += -DNDEBUG

all: 
	@echo Valid targets are generic and linux
generic: LTC4162-LADM_example_generic$(TARGETEXT)
	@echo Linking Complete 
linux: LTC4162-LADM_example_linux$(TARGETEXT)
	@echo Linking Complete

LTC4162-LADM_example_generic$(TARGETEXT): LTC4162-LADM_example_generic.o LTC4162-LADM.o LTC4162-LADM_pec.o LTC4162-LADM_reg_config.o LTC4162-LADM_bf_config.o
	@echo Linking $^ into $@
	$(CC) $(CFLAGS) -o $@ $^

LTC4162-LADM_example_linux$(TARGETEXT): LTC4162-LADM_example_linux.o LTC4162-LADM.o LTC4162-LADM_bf_config.o
	@echo Linking $^ into $@
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEADERS)
	@echo Compiling $< to $@
	$(CC) $(CFLAGS) -c $<

clean:
	@echo Cleaning up work area.
	$(RM) LTC4162-LADM_example_generic.o LTC4162-LADM_example_linux.o LTC4162-LADM.o LTC4162-LADM_pec.o LTC4162-LADM_reg_config.o LTC4162-LADM_bf_config.o LTC4162-LADM_example_generic$(TARGETEXT) LTC4162-LADM_example_linux$(TARGETEXT)
