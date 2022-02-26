TARGET ?= a.out
SRC_DIRS ?= ./src

SRCS := $(shell find $(SRC_DIRS) -name *.cpp)
OBJS := $(addsuffix .o,$(basename $(SRCS)))
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP
# CXXFLAGS ?= -std=c++17 -O2 -Wall -Wextra -pedantic -Wconversion -Wsign-conversion
override CXXFLAGS += -Wall -Wextra -pedantic -Wconversion -Wsign-conversion

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS) $(DEPS)

-include $(DEPS)
