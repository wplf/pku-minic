#pragma once

#include <iostream>  // 包含cout, cin, endl等
#include <sstream>
#include <memory>
#include <string>


using namespace std;  // 可以直接使用cout

constexpr const char* INDENT = " ";

using oss = std::ostringstream;

class BaseAST {
 public:
  virtual ~BaseAST() = default;
  virtual void Dump(oss&) const = 0;
};

// CompUnit 是 BaseAST
class CompUnitAST : public BaseAST {
 public:
  // 用智能指针管理对象
  std::unique_ptr<BaseAST> func_def;
  void Dump(oss& outstr) const override {
    // outstr << "CompUnitAST { ";
    func_def->Dump(outstr);
    // std::cout << " }";
  }
};

// FuncDef 也是 BaseAST
class FuncDefAST : public BaseAST {
 public:
  std::unique_ptr<BaseAST> func_type;
  std::string ident;
  std::unique_ptr<BaseAST> block;

  void Dump(oss& outstr) const override {
    // std::cout << "FuncDefAST { ";
    outstr << "fun @" << ident << "(): ";
    func_type->Dump(outstr);
    outstr << " {\n";
    block->Dump(outstr);
    outstr << "}\n";
  }
};

class FuncTypeAST : public BaseAST {
 public:
  std::string type;
  void Dump(oss& outstr) const override {
    outstr << type;
  }
};


class BlockAST : public BaseAST {
 public:
  std::unique_ptr<BaseAST> stmt;

  void Dump(oss& outstr) const override {
    // std::cout << "BlockAST { ";
    outstr << "%entry:";
    stmt->Dump(outstr);
    // std::cout << " }";
  }
};


class StmtAST : public BaseAST {
 public:
  int number; 

  void Dump(oss& outstr) const override {
    outstr << INDENT << "ret" << INDENT << number << '\n';
    // std::cout << "StmtAST " << "{ " << number << " }";
  }
};


