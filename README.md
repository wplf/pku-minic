# 武破立法的pku-minic 学习进度记录

- [x] 学习 flex 和 bison 的基本语法， 并添加对应的注释
- [x] 完成 lv1 的作业，通过记录如下
```bash
# docker run -it  --name pku-minic  -v  /Users/wplf/Projects/pku-minic:/root/compiler maxxing/compiler-dev  bash
# autotest -koopa -s lv1 /root/compiler

running test "0_main" ... PASSED
running test "1_comments" ... PASSED
running test "2_int_dec" ... PASSED
running test "3_int_oct" ... PASSED
running test "4_int_hex" ... PASSED
running test "5_compact" ... PASSED
running test "6_whitespaces" ... PASSED
PASSED (7/7)
```


> 该项目是从 https://github.com/pku-minic/sysy-make-template fork 而来，如果需要原始仓库，可以查看对应链接