#Compiler and Linker
CC          := c++ 

#The Target Binary Program
TARGET      := brainz

#The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR      := ./
TARGETDIR   := ./
SRCEXT      := cpp
OBJEXT      := o

#Flags, Libraries and Includes
CFLAGS      := -Wfatal-errors -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Werror -g -std=c++11
#---------------------------------------------------------------------------------
#DO NOT EDIT BELOW THIS LINE
#---------------------------------------------------------------------------------
SOURCES     := main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
OBJECTS     := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))
DEPS        := $(OBJECTS:.o=.d)

#Default Make

all: $(TARGETDIR)/$(TARGET) 

# Dependencies
-include $(DEPS)

#Remake
re: fclean all

#Clean only Objects
clean:
	@$(RM) -rf *.d
	@$(RM) -rf *.$(OBJEXT)

#Full Clean, Objects and Binaries
fclean: clean
	@$(RM) -rf $(TARGET)

$(TARGETDIR)/$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)  

#Compile
%.$(OBJEXT): %.$(SRCEXT)
	$(CC) $(CFLAGS) -MMD -c $< -o $@ 
