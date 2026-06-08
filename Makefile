CC      = gcc
CFLAGS  = $(shell pkg-config --cflags gtk4) -Iinclude -Wall -std=c11
LIBS    = $(shell pkg-config --libs gtk4)
OBJDIR  = build

OBJS = $(OBJDIR)/main.o $(OBJDIR)/file_manager.o $(OBJDIR)/core.o $(OBJDIR)/open_puma_ui_controller.o


main: $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(OBJDIR)/main

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/main.o: src/main.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/main.c -o $(OBJDIR)/main.o

$(OBJDIR)/file_manager.o: src/file_manager.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/file_manager.c -o $(OBJDIR)/file_manager.o

$(OBJDIR)/core.o: ui/core.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c ui/core.c -o $(OBJDIR)/core.o

$(OBJDIR)/open_puma_ui_controller.o: src/open_puma_ui_controller.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/open_puma_ui_controller.c -o $(OBJDIR)/open_puma_ui_controller.o

compile_commands.json:
	bear -- make main

clean:
	rm -f $(OBJDIR)/*.o $(OBJDIR)/main
