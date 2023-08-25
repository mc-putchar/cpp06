# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/25 07:01:42 by mcutura           #+#    #+#              #
#    Updated: 2023/08/25 07:01:42 by mcutura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Targets ---
NAME := a.out
# --- Sources ---
SRCS := main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp
SRCS += RobotomyRequestForm.cpp PresidentialPardonForm.cpp
SRCS += Intern.cpp
# --- Objects ---
OBJS := $(SRCS:%.cpp=%.o)
# --- Headers ---
HDRS := Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp
HDRS += RobotomyRequestForm.hpp PresidentialPardonForm.hpp
HDRS += Intern.hpp
# --- Compilers ---
CC := gcc
CXX := g++
# --- Flags ---
CFLAGS := -Wall -Wextra -Werror -pedantic-errors
debug: CFLAGS += -ggdb3
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -pedantic-errors
debug: CXXFLAGS += -ggdb3
# --- Utils --
RM := rm -rf

# --- Rules ---
all: $(NAME)

$(NAME): $(OBJS) $(HDRS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	
$(OBJS) : %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

debug: all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean debug fclean re