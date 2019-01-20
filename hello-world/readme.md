# hello-world

## 登录树莓派

1. 方案一: `ssh pi@192.168.1.106`
2. 方案二: `ssh pi@raspberrypi.local`

## GCC

- 生成可执行文件  `gcc hello.c -o hello`
- 执行可执行文件 `./hello`

## 交叉编译

### 安装树莓派官方交叉编译工具

- 在宿主机下载树莓派官方交叉编译工具
  `git clone git://github.com/raspberrypi/tools.git`

- 将bin文件添加到环境变量
  1. 打开`~/.bashrc`文件
  2. 在最后添加 `export PATH=$PATH:$HOME/raspberry/raspberry-src/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin`
  3. `source .bashrc` 立刻生效
  4. `echo $PATH`打印系统变量
    >echo命令用于在shell中打印shell变量的值，或者直接输出指定的字符串。

### 宿主机环境使wiringPi

1. 宿主机下载wiringPi, 只需要下载即可, 我们只需要使用他的.h文件.我安装在`/home/joetu/raspberry/wiringPi`
2. 树莓派上下载wiringPi,安装完成后执行./build可执行文件,会在/usr/local/lib目录下生成`libwiringPiDev.so.2.46` 和`libwiringPi.so.2.46`动态链接库
3. 将这两个文件拷贝到宿主机`home/joetu/raspberry/raspberry-dev/wiringPi-lib`
4. 创建其无版本号的软连接：
    ~~~c
    ln -s  libwiringPi.so.2.25   libwiringPi.so
    ln -s  libwiringPiDev.so.2.25   libwiringPiDev.so
    ~~~

5. vscode 在`.vscode/c_cpp_properties.json`中 `"includePath"`下添加wringPi的路径:
    ~~~json
    "includePath": [
                "${workspaceFolder}/**",
                "/home/joetu/raspberry/wiringPi/wiringPi/**"
            ]
    ~~~~
6. 在vscode下编写代码
7. 编写makefile文件