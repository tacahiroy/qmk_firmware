SRC += tacahiroy.c

ifeq ($(strip $(LEADER_ENABLE)), yes)
     SRC += leader.c
endif
