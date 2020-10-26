# Makefile created by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
# 
# Copyright (C) 2020
# 
# Begin's date: 10/08/2020
# Date of last modification: 26/10/2020

TARGET = despack
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin
SRC    = $(wildcard $(SRCDIR)/*.c)
INC    = -I $(INCDIR)
OBJ    = $(addprefix $(OBJDIR)/,main.o install_process.o download.o \
                                unpack.o compile.o register_package.o \
                                list_packages.o update.o verify_instalation.o get_date_time.o \
                                search.o uninstall.o install.o upgrade.o verify_package.o)
BIN    = $(BINDIR)/$(TARGET)
CC     = gcc
CFLAGS = -lcurl -lfatec

all: $(OBJDIR) $(BINDIR) $(BIN)

$(OBJDIR):
	mkdir $@
$(BINDIR):
	mkdir $@
$(BIN): $(OBJ)
	$(CC) -o $@ $(OBJ) $(CFLAGS) 
$(OBJDIR)/main.o: $(SRCDIR)/main.c $(INCDIR)/package.h
	$(CC) -c $< -o $@
$(OBJDIR)/install_process.o: $(SRCDIR)/install_process.c $(INCDIR)/package.h
	$(CC) -c $< -o $@
$(OBJDIR)/download.o: $(SRCDIR)/download.c $(INCDIR)/package.h
	$(CC) -c $< -o $@
$(OBJDIR)/unpack.o: $(SRCDIR)/unpack.c $(INCDIR)/package.h
	$(CC) -c $< -o $@
$(OBJDIR)/compile.o: $(SRCDIR)/compile.c $(INCDIR)/package.h
	$(CC) -c $< -o $@
$(OBJDIR)/verify_instalation.o: $(SRCDIR)/verify_instalation.c $(INCDIR)/package.h
	$(CC) -c $< -o $@
$(OBJDIR)/register_package.o: $(SRCDIR)/register_package.c $(INCDIR)/package.h
	$(CC) -c $< -o $@
$(OBJDIR)/list_packages.o: $(SRCDIR)/list_packages.c $(INCDIR)/package.h
	$(CC) -c $< -o $@
$(OBJDIR)/install.o: $(SRCDIR)/install.c $(INCDIR)/package.h
	$(CC) -c $< -o $@
$(OBJDIR)/uninstall.o: $(SRCDIR)/uninstall.c $(INCDIR)/package.h
	$(CC) -c $< -o $@
$(OBJDIR)/update.o: $(SRCDIR)/update.c $(INCDIR)/package.h
	$(CC) -c $< -o $@
$(OBJDIR)/search.o: $(SRCDIR)/search.c $(INCDIR)/package.h
	$(CC) -c $< -o $@
$(OBJDIR)/compress.o: $(SRCDIR)/compress.c $(INCDIR)/package.h
	$(CC) -c $< -o $@
$(OBJDIR)/get_date_time.o: $(SRCDIR)/get_date_time.c $(INCDIR)/package.h
	$(CC) -c $< -o $@
$(OBJDIR)/verify_package.o: $(SRCDIR)/verify_package.c $(INCDIR)/package.h
	$(CC) -c $< -o $@
$(OBJDIR)/upgrade.o: $(SRCDIR)/upgrade.c $(INCDIR)/package.h
	$(CC) -c $< -o $@
run: all
	@$(BIN)
#install: all
#	mkdir -p /usr/share/despack/packages/
#	cp despack.list /usr/share/despack/
#	cp despack.8.gz /usr/share/man/man8/
#	cp ./bin/despack /usr/sbin/
#uninstall:
#	mkdir -p /usr/share/despack/packages/
#	rm /usr/share/despack/despack.list
#	rm /usr/share/man/man8/despack.8.gz
#	rm /usr/sbin/despack
clean:
	rm -rf $(OBJ)
mrproper: clean
	rm -rf $(BINDIR)
	rm -rf $(OBJDIR)
.PHONY: all run clean mrproper install uninstall
