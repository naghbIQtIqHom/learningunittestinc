.PHONY: all build test clean run

CC=gcc
CFLAGS=-Wall -Wextra -std=c17
CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=gnu++2b
LDFLAGS=
LDFLAGS_UNITTEST= -lCatch2Main -lCatch2
LDFLAGS_UNRESOLVEDSYMBOL = -Wl,--unresolved-symbols=ignore-in-object-files

SRC_DIR=src
OBJ_DIR=obj
BIN_DIR=bin

SRC_FILES=$(wildcard $(SRC_DIR)/*.c)
OBJ_FILES=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))


all: build test


TARGET=$(BIN_DIR)/calc

$(TARGET): $(OBJ_FILES) | $(BIN_DIR)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $^


TEST_DIR=test
TEST_FILES=$(wildcard $(TEST_DIR)/*.cpp)
OBJ_UNITTEST_DIR=obj/obj_unittest
OBJ_UNITTEST_FILES=$(patsubst $(TEST_DIR)/%.cpp,$(OBJ_UNITTEST_DIR)/%.o,$(TEST_FILES))
OBJ_UNITTEST_SRC_DIR=obj/obj_unittest_src
OBJ_UNITTEST_SRC_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_UNITTEST_SRC_DIR)/%.o,$(SRC_FILES))
OBJ_UNITTEST_SRC_FILES := $(filter-out $(OBJ_UNITTEST_SRC_DIR)/main.o,$(OBJ_UNITTEST_SRC_FILES))

UNITTEST_TARGET_DEC=$(BIN_DIR)/test_calc_declare_dummy_func
UNITTEST_TARGET_OPT=$(BIN_DIR)/test_calc_with_option_unsolved_symbol

$(OBJ_UNITTEST_SRC_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_UNITTEST_SRC_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_UNITTEST_DIR)/%.o: $(TEST_DIR)/%.cpp | $(OBJ_UNITTEST_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $^


# nothing()のシンボルを自分で定義して解決する。
$(UNITTEST_TARGET_DEC): $(OBJ_UNITTEST_DIR)/test_calc.o $(OBJ_UNITTEST_SRC_DIR)/calc.o | $(OBJ_UNITTEST_DIR) $(OBJ_UNITTEST_SRC_DIR) $(BIN_DIR)
	$(CXX) -o $@ $^ $(LDFLAGS_UNITTEST)

# nothing()のシンボルをリンカのオプションで解決したことにする。
$(UNITTEST_TARGET_OPT): $(OBJ_UNITTEST_DIR)/test_calc_with_opt.o $(OBJ_UNITTEST_SRC_DIR)/calc.o | $(OBJ_UNITTEST_DIR) $(OBJ_UNITTEST_SRC_DIR) $(BIN_DIR)
	$(CXX) -o $@ $^ $(LDFLAGS_UNITTEST) $(LDFLAGS_UNRESOLVEDSYMBOL)



build: $(TARGET) $(UNITTEST_TARGET_DEC)

test: $(UNITTEST_TARGET_DEC) $(UNITTEST_TARGET_OPT)
	$(UNITTEST_TARGET_DEC)
	$(UNITTEST_TARGET_OPT)

run: $(TARGET)
	- $(TARGET)

$(OBJ_DIR) $(BIN_DIR) $(OBJ_UNITTEST_DIR) $(OBJ_UNITTEST_SRC_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(OBJ_UNITTEST_DIR) $(OBJ_UNITTEST_SRC_DIR)
