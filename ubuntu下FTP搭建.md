# **ubuntu下搭建FTP服务器**

# 1. 为FTP创建一个目录:

```shell
$ mkdir ~/ftp
```

# 2.进入ftp目录，创建一个文件test，用来测试ftp

```shell
$ cd ~/ftp
$ touch test
```

# 3.安装ftp服务器

```shell
$ sudo apt-get install vsftpd
```

## 3.1 修改配置文件(需要root权限)

```shell
$ sudo vim /etc/vsftpd.conf
```
## 3.2 添加以下内容

```shell
    "允许匿名登录
    anonymous_enable=YES
    "ftp服务器的目录
    anon_root=/home/ubuntu/ftp
    "登录无需密码
    no_anon_password=YES
    "允许文件写入
    write_enable=YES
    "允许上传文件
    anon_upload_enable=YES
    "允许创建目录
    anon_mkdir_write_enable=YES
```
    保存退出

# 4.重启服务器，重新加载/etc/vsftpd.conf配置文件
```shell
    $ sudo /etc/init.d/vsftpd restart
```

# 5.测试ftp
## 1.在终端输入命令：
```shell
    $  ftp 127.0.0.1
```
## 2.在浏览器中输入：
    ftp:\\127.0.0.1

# 6.退出ftp
```shell
    ftp> bye
```









