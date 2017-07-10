#=======================================================================================#
# ipc_lb_gtest_make.mk
#=======================================================================================#
#  Created on: Oct 3, 2015
#      Author: puch
#=======================================================================================#

#=======================================================================================#
# DEFINE PACKAGE RULE
#=======================================================================================#
define $(_flavor_)_$(_feat_)_MAKE
#=======================================================================================#
# OBJECTS DIRECTORY
# e.g: 
#     $(_flavor_)_$(_feat_)_src_dir=pk_module_N_code/_src
#     or
#     $(_flavor_)_$(_feat_)_src_dir=_src
#=======================================================================================#
$(_flavor_)_$(_feat_)_inc=

#=======================================================================================#
# BIN REQUISITES
#=======================================================================================#

##
 # Object Requisites
 # e.g: $(_flavor_)_$(_feat_)_bin_objs=$($(_flavor_)_OBJ_DIR)/my_bin_obj$(_obj_ext_) \
 ##
$(_flavor_)_$(_feat_)_bin_objs=\
ipc_lb_gtest \
ipc_gtest \
mailbox_gtest \
mail_gtest \
publisher_gtest \
dbg_log_gtest \

##
 # Library Requisites
 # e.g: $(_flavor_)_$(_feat_)_bin_libs=
 ##

$(_flavor_)_$(_feat_)_bin_libs=\
dbg_log \
gtest_task \
ipc_gtest_worker \
gtest \
ipc_lb \
object \

##
 # Target Binary
 # e.g: $(_flavor_)_$(_feat_)_bin=my_bin
 ##
$(_flavor_)_$(_feat_)_bin=ipc_gtest
#=======================================================================================#
# END PACKAGE RULE
#=======================================================================================#
endef
#=======================================================================================#
# LOCAL VARIABLES
#=======================================================================================#

#=======================================================================================#
# LOCAL DEFINES 
#=======================================================================================#

#=======================================================================================#
# LOCAL DEFINE EXPANSIONS
#=======================================================================================#

#=======================================================================================#
# LOCAL RULES EXPANSIONS
#=======================================================================================#

#=======================================================================================#
# INCLUDE PK PROJECT UTILITY
#=======================================================================================#
include $(PROJ_MAK_DIR)/epilog.mk
#=======================================================================================#
# ipc_lb_gtest_make.mk
#=======================================================================================#
# Changes Log
#
#
#=======================================================================================#