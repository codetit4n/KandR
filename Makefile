CC = cc
CFLAGS = -std=c89 -Wall -Wextra -pedantic -O2
BUILD = build
SRC = src

.PHONY: clean run help
.DEFAULT_GOAL := help

EX := $(filter-out run clean help,$(MAKECMDGOALS))
EX_ONE := $(firstword $(EX))

help:
	@echo "Usage:"
	@echo "  make <ex>        Build src/<ex>.c -> build/<ex>     (e.g. make 1-1)"
	@echo "  make run <ex>    Build (if needed) and run          (e.g. make run 1-1)"
	@echo "  make clean       Remove the build directory"
	@echo ""
	@echo "Layout:"
	@echo "  src/1-1.c, src/2-4.c, ..."

%:
	@mkdir -p $(BUILD)
	@src="$(SRC)/$@.c"; \
	out="$(BUILD)/$@"; \
	if [ ! -f "$$src" ]; then \
		echo "Missing $$src" 1>&2; exit 1; \
	fi; \
	echo "[CC] $$src -> $$out"; \
	$(CC) $(CFLAGS) "$$src" -o "$$out"

run: $(EX_ONE)
	@if [ -z "$(EX_ONE)" ] || [ "$(words $(EX))" -ne 1 ]; then \
		echo "Usage: make run <ex>   (example: make run 1-1)" 1>&2; \
		exit 1; \
	fi
	@echo "[RUN] ./$(BUILD)/$(EX_ONE)"
	@printf "_______________________________________\n\n"
	@./$(BUILD)/$(EX_ONE)
	@printf "\n_______________________________________\n"

clean:
	rm -rf $(BUILD)

