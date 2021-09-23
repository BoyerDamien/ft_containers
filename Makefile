# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/10 16:36:02 by dboyer            #+#    #+#              #
#    Updated: 2021/09/23 20:04:14 by dboyer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#									SOURCES
################################################################################

NAME    			=	ft_containers

MAIN				= 	main.cpp

SRCS    			= 	assert\
						test_map\
						test_vector\
						test_pair\
						test_stack

INCLUDES			=	-I ./includes

HEADERS				=  	iterators/iterator_traits\
						iterators/iterator\
						iterators/reverse_iterator\
						map/bst_element\
						map/map_iterator\
						map/map\
						stack/stack\
						test/test_accessors\
						test/test_capacity\
						test/test_constructors\
						test/test_intern_type\
						test/test_iterators\
						test/test_modifiers\
						test/test_operations\
						test/operators\
						test/test_utils\
						test/test\
						test/unittest\
						vector/vector_iterator\
						vector/vector\
						algorithms\
						ft_containers\
						type_traits\
						utility


HEADERS_FIL			= $(addsuffix .hpp, $(addprefix ./includes/, $(HEADERS)))

FIL					= $(addsuffix .cpp, $(addprefix ./srcs/, $(SRCS)))

OBJS				= 	$(FIL:.cpp=.o)
OBJS_MAIN			= 	$(MAIN:.cpp=.o)


CXXFLAGS  			= 	-Werror -Wall -Wextra -std=c++98 -O2 ${INCLUDES}
CXX     			= 	clang++
RM      			= 	rm -f

################################################################################
#								Basic Rules
################################################################################

%.o: %.cpp ${HEADERS_FIL}
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

.PHONY  :	all clean fclean re%