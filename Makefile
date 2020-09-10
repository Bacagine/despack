# Makefile created by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
# 
# Copyright (C) 2020
# 
# Begin's date: 08/10/2020
# Date of last modification: 09/04/2020

TARGET = despack
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin
SRC    = $(wildcard $(SRCDIR)/*.c)
INC    = -I $(INCDIR)
OBJ    = $(addprefix $(OBJDIR)/,main.o install_process.o download.o \
                                descompactar.o compile.o cadastrar_pacote.o \
                                list.o update.o verifica_instalacao.o get_date_time.o)
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
$(OBJDIR)/descompactar.o: $(SRCDIR)/descompactar.c $(INCDIR)/package.h
	$(CC) -c $< -o $@
$(OBJDIR)/compile.o: $(SRCDIR)/compile.c $(INCDIR)/package.h
	$(CC) -c $< -o $@
$(OBJDIR)/cadastrar_pacote.o: $(SRCDIR)/cadastrar_pacote.c $(INCDIR)/package.h
	$(CC) -c $< -o $@
$(OBJDIR)/list.o: $(SRCDIR)/list.c $(INCDIR)/package.h
	$(CC) -c $< -o $@
$(OBJDIR)/update.o: $(SRCDIR)/update.c $(INCDIR)/package.h
	$(CC) -c $< -o $@
#$(OBJDIR)/compactar.o: $(SRCDIR)/compactar.c $(INCDIR)/package.h
#	$(CC) -c $< -o $@
#$(OBJDIR)/upgrade.o: $(SRCDIR)/upgrade.c $(INCDIR)/package.h
#	$(CC) -c $< -o $@
$(OBJDIR)/verifica_instalacao.o: $(SRCDIR)/verifica_instalacao.c $(INCDIR)/package.h
	$(CC) -c $< -o $@
$(OBJDIR)/get_date_time.o: $(SRCDIR)/get_date_time.c $(INCDIR)/package.h
	$(CC) -c $< -o $@
run: all
	@$(BIN)
install: all
	mkdir -p /usr/share/despack/packages/
	cp despack.list /usr/share/despack/
	cp despack.8.gz /usr/share/man/man8/
	cp ./bin/despack /usr/sbin/
uninstall:
	mkdir -p /usr/share/despack/packages/
	rm /usr/share/despack/despack.list
	rm /usr/share/man/man8/despack.8.gz
	rm /usr/sbin/despack
clean:
	rm -rf $(OBJ)
mrproper: clean
	rm -rf $(BINDIR)
	rm -rf $(OBJDIR)
.PHONY: all run clean mrproper install uninstall
