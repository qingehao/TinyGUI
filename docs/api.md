# TinyGUI API

## 

> 注意：对于函数介绍，必须遵循下面的格式

`void tg_text_show_string(uint8_t x,uint8_t y,tg_font_t font,char *str,uint8_t mode)``

指定位置显示一串字符，支持中英文混合显示。

| 参数              | 描述                                |
|:------------------|:------------------------------------|
|x               | 横坐标                         |
|y | 纵坐标 |
|font | 字体 |
|*str | 待显示字符 |
|mode | 0:正常显示 1:反白显示 |
| **返回**          | **描述**                                |
|无                  |                             |

`void tg_text_show_string_mid(uint16_t x,uint16_t y,tg_font_t font,char*str,uint8_t mode,uint16_t len)``

指定位置居中显示一串字符，支持中英文混合显示。

| 参数     | 描述                  |
| :------- | :-------------------- |
| x        | 横坐标                |
| y        | 纵坐标                |
| font     | 字体                  |
| *str     | 待显示字符            |
| mode     | 0:正常显示 1:反白显示 |
| len      | 显示区域宽度          |
| **返回** | **描述**              |
| 无       |                       |

`void tg_text_set_spacing(uint8_t letter,uint8_t line)``

设置文本显示的间距以及行间距

| 参数     | 描述     |
| :------- | :------- |
| letter   | 字符间距 |
| line     | 行间距   |
| **返回** | **描述** |
| 无       |          |

