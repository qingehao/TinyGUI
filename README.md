# TinyGUI

## 1、介绍

> 说明：你需要在这里对项目进行简单的介绍，描述项目背景，当前现状、功能特点等等……

TinyGUI是一款轻量级单色屏GUI，提供了常用的绘图函数、窗口、消息框、滚动条及菜单功能。详细的DEMO见 https://b23.tv/NAxVHI。

### 1.1 目录结构

> 说明：参考下面表格，整理出 packages 的目录结构

| 名称 | 说明 |
| ---- | ---- |
| docs  | 文档目录 |
| examples | 例子目录，并有相应的一些说明 |
| inc  | 头文件目录 |
| src  | 源代码目录 |
| port | 移植代码目录。如果没有移植代码，可以不需要 |

### 1.2 许可证

> 说明：请在这里说明该 package 的授权许可，例如： GPLv2、LGPLv2.1、MIT、Apache license v2.0、BSD 等。

hello package 遵循 LGPLv2.1 许可，详见 `LICENSE` 文件。

### 1.3 依赖

> 说明：列出该 package 对于其他 package 、RT-Thread 操作系统版本等软件方面的依赖关系。

- RT-Thread 3.0+
- SPI驱动

## 2、如何打开 TinyGUI

> 说明：描述该 package 位于 menuconfig 的位置，并对与其相关的配置进行介绍

使用 hello package 需要在 RT-Thread 的包管理器中选择它，具体路径如下：

```
RT-Thread online packages
    multimedia packages --->
        [*] TinyGUI
```

然后让 RT-Thread 的包管理器自动更新，或者使用 `pkgs --update` 命令更新包到 BSP 中。

## 3、使用 TinyGUI

> 说明：在这里介绍 package 的移植步骤、使用方法、初始化流程、准备工作、API 等等，如果移植或 API 文档内容较多，可以将其独立至 `docs` 目录下。

1.使用本GUI制作的DEMO视频见https://b23.tv/NAxVHI

1.在软件包管理器中选中他。

2.修改屏幕驱动部分，假如你使用的是SSD1306 128X64 OLED屏幕，那么你可以直接使用其中的驱动，根据你实际的硬件连接选择使用哪个SPI。并修改drv_oled.c中第13行、第14行、第287行。

3.使用tg_example.c中的例子测试。



## 4、注意事项

> 说明：列出在使用这个 package 过程中需要注意的事项；列出常见的问题，以及解决办法。

## 5、联系方式 & 感谢

* 维护：qingehao
* 主页：https://github.com/qingehao/TinyGUI
