//#####################################################################
// Copyright 2009, Jerry Talton.
// This software is governed by the license contained in LICENSE.
//#####################################################################
#ifndef _AMPERSAND_SYMBOL_HPP_
#define _AMPERSAND_SYMBOL_HPP_

#include "Symbol.hpp"

namespace ProceduralModeling{

//#####################################################################
// Class AmpersandSymbol
//#####################################################################
class AmpersandSymbol : public Symbol
{
public:
    AmpersandSymbol(Symbol** symbolTable)
     :Symbol(true,1,2,0,1,symbolTable)
    {}

    AmpersandSymbol(const bool isTerminal,const uint maxNumSymbols,const uint maxNumSymbolEntries,const uint numDiffusionParams,const uint numFormalParams,Symbol** symbolTable)
     :Symbol(isTerminal,maxNumSymbols,maxNumSymbolEntries,numDiffusionParams,numFormalParams,symbolTable)
    {}

    virtual void render(const float* params) const
    {
        glRotatef(-params[0],1,0,0);
    }

    virtual uint produce(const SymbolEntry* input,SymbolEntry* output,float& logProbability) const
    {
        output[0].mID=4;
        output[1].mParam=input[0].mParam;
        logProbability=0;
        return 2;
    }

    virtual ushort setFlags(const float* params) const
    {
        return SymbolEntry::DETERMINISTIC;
    }

    virtual void saveToMesh(const float* params) const
    {
        mResourceHandler->getOutputMesh()->curDirTrans().rotate(-params[0],1,0,0);
    }

    virtual const char* symbolName() const
    { return "&"; }

//#####################################################################
};

//#####################################################################
} // namespace ProceduralModeling

#endif //_AMPERSAND_SYMBOL_HPP_
