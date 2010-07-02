#ifndef TOSATBASE_H
#define TOSATBASE_H

#include "../AST/AST.h"
#include "../STPManager/STPManager.h"

namespace BEEV
{
  class ToSATBase
  {
  protected:
    ASTNode ASTTrue, ASTFalse, ASTUndefined;

    // Ptr to STPManager
    STPMgr * bm;

  public:

    typedef HASHMAP<
    ASTNode,
    vector<unsigned>,
    ASTNode::ASTNodeHasher,
    ASTNode::ASTNodeEqual> ASTNodeToVar;

    // Constructor
    ToSATBase(STPMgr * bm) :
      bm(bm)
    {
      ASTTrue      = bm->CreateNode(TRUE);
      ASTFalse     = bm->CreateNode(FALSE);
      ASTUndefined = bm->CreateNode(UNDEFINED);
    }

    virtual ~ToSATBase()
    {}

    //print the STP solver output
    void PrintOutput(SOLVER_RETURN_TYPE ret);

    // Bitblasts, CNF conversion and calls toSATandSolve()
    virtual bool CallSAT(MINISAT::Solver& SatSolver, const ASTNode& input) =0;

    virtual ASTNodeToVar& SATVar_to_SymbolIndexMap()= 0;

    virtual void ClearAllTables(void)  =0;
  };
}

#endif