# 生成ssh公匙
1.进入ssh目录
```shell
cd .ssh
```
2.生成公匙
```shell
ssh-keygen -t rsa -C "你的邮箱名"
```
3. 将id_rsa.pub的内容拷进github的仓库中


# github 上传文件

(aname相当于变量名)
1.创建git文件夹
```shell
$: git init
```
2.连接github
```shell
$: git remote add aname git@github.com：XXX/∗∗.git
"eg git remate add aname git@github.com:xxxyue-cen/xxxyue-cen.github.io.git
```
xxx:表示github账号
** ：表示仓库名

3.将主分支放过来
```shell
$ : git pull aname master
```

4.添加当前文件下的所有文件
```shell
$ : git add .
```

5. 此次备注(日志)
```shell
$ : git commit -m "message"  
```

6. 将文件push到远程服务器，
```shell
$ : git push aname master   

```

# github删除文件(夹)

eg：删除image文件夹

1.将github上的文件重新拉下来
```shell
git pull aname master 
```
2.ls 查看当前目录
```shell
ls
```
3.删除文件
```shell 
git rm -r --cached image
```
4.修改记录 
```shell
git commit -m "删除了image"
```
5.更新仓库
```shell
git push -u aname master 
```
