
# git的基本操作


# 创建版本
```
$  git init
```

# 添加文件
git  add  文件名
eg： git add code.txt

# 创建版本记录
git commit  -m "版本"

# 查看记录
git log

# 版本回退
HEAD 表示最新的版本  一个指针，指向当前版本
HEAD^  表示HEAD版本的上一个版本
HEAD~1  表示HEAD版本的上一个版本
HEAD~100  表示HEAD版本的前100个版本

## 后移
```
git reset --hard   HEAD^
```

## 前移
```
git reset  --hard    序列号前几位
```

# 查看操作记录
 
git  reflog

# 查看当前状态

git  status

# 撤销修改  撤销在工作区的文件
git checkout --  文件名

# 取消暂存  撤销暂存区的文件
git reset HEAD  文件名
git cheakout --  文件名

# 对比工作区的文件和版本的文件
git  diff HEAD -- 文件名 

## -表示版本里的文件
## + 表示工作区的文件
# 对比两个版本的文件的不同
git diff  HEAD HEAD^


# 删除文件
rm 文件名
git rm 文件名

# 查看所以版本记录
git  log  --pretty=oneline



# 分支管理  master   dev


# 查看分支
git branch

# 创建并切换新分支       dev 新分支名   
git checkout  -b   dev

# 创建分支
git branch 分支名

git branch dev

# 切换分支
git checkout 分支名
git checkout  master

# 合并分支  快速合并(指针往前移动)
git merge  dev

# 删除分支
git branch  -d  dev

# 查看分支图
git log  --graph --pretty=oneline

# 禁止快速合并,创建一次提交  分支名
git  merge --no-ff  -m "禁止快速合并，做一次新提交"dev

# 保存现场
git brash

# 获取保存现场记录
git brash list

#  恢复现场
git brash pop


# github

# git 出错
$ eval "$(ssh-agent -s)"
$ ssh-add


# 推送分支    将分支推送至远程仓库
git push  origin  分支名称

# 本地分支跟踪服务器的分支
git branch --set-upstream-to=origion/远程分支名称   本地分支名称


# 从远程分支拉取代码
git pull origin   分支名称











