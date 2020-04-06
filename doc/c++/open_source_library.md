## C/C++

### 视频
包含图像格式、图像处理、视频编解码等库介绍

#### imv(std_image)
仓库：https://github.com/nothings/stb<br>
官网：http://nothings.org/<br>
```c++ 
// 常用函数
stbi_load_from_memory
stbi_image_free
```
#### freeimage
仓库：https://sourceforge.net/projects/freeimage/files/<br>
官网：http://freeimage.sourceforge.net<br>
```c++ 
// 常用函数
FreeImage_Initialise(TURE);
FreeImage_GetFileType
FreeImage_GetFIFFromFilename
FreeImage_Load
FreeImage_GetBPP
FreeImage_GetWidth
FreeImage_GetHeight
FreeImage_GetPitch
FreeImage_Clone
FreeImage_ConvertTo32Bits
FreeImage_Save
FreeImage_Unload
FreeImage_DeInitialise();
```