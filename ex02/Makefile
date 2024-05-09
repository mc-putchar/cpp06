# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcutura <mcutura@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/25 07:01:42 by mcutura           #+#    #+#              #
#    Updated: 2024/05/09 20:10:14 by mcutura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := identify
SRCS := main.cpp Base.cpp
OBJS := $(SRCS:%.cpp=%.o)
HDRS := Base.hpp

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -Wpedantic
debug: CXXFLAGS += -ggdb3 -Og

RM := rm -rf

.PHONY: all clean debug fclean re

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
