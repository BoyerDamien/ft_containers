# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/10 16:36:02 by dboyer            #+#    #+#              #
#    Updated: 2021/05/26 11:27:44 by dboyer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#									SOURCES
################################################################################

NAME    			=	ft_containers

MAIN				= 	./srcs/main.cpp

SRCS    			= 	assert\
						test_list\
						test_vector

INCLUDES			=	-I ./includes

HEADERS				=	./includes/ft_containers.hpp


FIL					= $(addsuffix .cpp, $(addprefix ./srcs/, $(SRCS)))

OBJS				= 	$(FIL:.cpp=.o)
OBJS_MAIN			= 	$(MAIN:.cpp=.o)


CXXFLAGS  			= 	-Werror -Wall -Wextra -std=c++98 -O3 ${INCLUDES}
CXX     			= 	clang++
RM      			= 	rm -f

################################################################################
#								Basic Rules
################################################################################

%.o: %.cpp ${HEADERS}
	$(CXX) $(CXXFLAGS) -c $< -o $@

all     :	$(NAME)

$(NAME) :	$(OBJS) $(OBJS_MAIN)
	${CXX} ${CXXFLAGS} -o ${NAME} ${OBJS} ${OBJS_MAIN} 

clean   :
	$(RM) $(OBJS)
	$(RM) ${OBJS_MAIN}

fclean  : clean
	$(RM) $(NAME)

re      :	fclean all

################################################################################
#									Extra Rules
################################################################################
test 	:	all
	./${NAME}

.PHONY  :	all clean fclean re bonus%
