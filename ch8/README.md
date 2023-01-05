# 第8章 IO库
## 8.1 IO类
### 8.1.1 IO对象无拷贝或赋值

### 8.1.3 管理输出缓冲
略

## 8.2 文件输入输出
### 8.2.1 使用文件流对象
ifstream 从给定文件流中读取数据
ofstream 向给定文件流写入数据
```c++
ifstream in(ifile);
ofstream out;
out.open(ifile + ".copy");
```
