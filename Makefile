# Makefile created by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
# 
# Copyright (C) 2020
# 
# Date of begin: 10/08/2020
# Date of last modification: 10/08/2020

TARGET = despack
SRCDIR = ./src
INCDIR = ./include
OBJDIR = ./obj
BINDIR = ./bin
SRC    = $(wildcard $(SRCDIR)/*.c)
INC    = -I $(INCDIR)
OBJ    = $(addprefix $(OBJDIR)/,main.o install_process.o download.o
                                descompactar.o compile.o cadastrar_pacote.o
                                list.o update.o compactar.o upgrade.o
                                fatec.o data.o)
BIN    = $(BINDIR)/$(TARGET)
CC     = gcc
#CFLAGS = 

all: OBJDIR BINDIR BIN

OBJDIR:
	mkdir $@
BINDIR:
	mkdir $@
$(BIN): $(OBJ)
	$(CC) $@ $< $(CFLAGS) 
$(OBJDIR)/main.o: $(SRCDIR)/main.c $(INCDIR)/package.h
	$(CC) $< -c $@
$(OBJDIR)/install_process.o: $(SRCDIR)/install_process.c $(INCDIR)/package.h
	$(CC) $< -c $@
$(OBJDIR)/download.o: $(SRCDIR)/download.c $(INCDIR)/package.h
	$(CC) $< -c $@
$(OBJDIR)/descompactar.o: $(SRCDIR)/descompactar.c $(INCDIR)/package.h
	$(CC) $< -c $@
$(OBJDIR)/compile.o: $(SRCDIR)/compile.c $(INCDIR)/package.h
	$(CC) $< -c $@
$(OBJDIR)/cadastrar_pacote.o: $(SRCDIR)/cadastrar_pacote.c $(INCDIR)/package.h
	$(CC) $< -c $@
$(OBJDIR)/list.o: $(SRCDIR)/list.c $(INCDIR)/package.h
	$(CC) $< -c $@
$(OBJDIR)/update.o: $(SRCDIR)/update.c $(INCDIR)/package.h
	$(CC) $< -c $@
$(OBJDIR)/compactar.o: $(SRCDIR)/compactar.c $(INCDIR)/package.h
	$(CC) $< -c $@
$(OBJDIR)/upgrade.o: $(SRCDIR)/upgrade.c $(INCDIR)/package.h
	$(CC) $< -c $@
$(OBJDIR)/fatec.o: $(SRCDIR)/fatec.c $(INCDIR)/package.h
	$(CC) $< -c $@
$(OBJDIR)/data.o: $(SRCDIR)/data.c $(INCDIR)/package.h
	$(CC) $< -c $@

