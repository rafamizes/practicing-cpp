# valgrind --leak-check=full program;
TARGET ?= leak_prog
SRC_DIRS ?= ./src

SRCS := $(shell find $(SRC_DIRS) -name *.cpp)
OBJS := $(addsuffix .o,$(basename $(SRCS)))
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP
# override CXXFLAGS += -std=c++20 -Wall -Wextra -pedantic -Wconversion -Wsign-conversion
# for shared libraries include -fPIC
# check what does -pipe flag do
CXXFLAGS ?= -g -O0 -std=c++17 -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion -Wuseless-cast -Wshadow -Wno-deprecated -Wvla -Wextra-semi -Wnull-dereference -Wswitch-enum -Wduplicated-cond -Wduplicated-branches -Wsuggest-override -fsanitize=address -fno-omit-frame-pointer -fsanitize=undefined

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS) $(DEPS)

-include $(DEPS)
