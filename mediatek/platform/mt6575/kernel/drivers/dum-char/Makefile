include $(MTK_ROOT_BUILD)/Makefile
ifeq ($(CONFIG_MTK_MMC),y)
  CONFIG_MTK_USIF = y
else
	ifeq ($(CONFIG_MTK_MTD_NAND),y)
  	CONFIG_MTK_USIF = y
  	else
  	CONFIG_MTK_USIF = n
  	endif
endif
#obj-$(CONFIG_MTK_USIF) += $(call to-root,$(obj))mediatek/custom/out/$(call lc,$(MTK_PROJECT))/common/partition_define.o
obj-$(CONFIG_MTK_USIF) += DumChar.o
DumChar-objs :=  dumchar.o partition_define.o

