//
// ex: set ro:
// DO NOT EDIT.
// generated by smc (http://smc.sourceforge.net/)
// from file : recognizerClass.sm
//

#include "recognizerClass.h"
#include "recognizerClass_sm.h"

using namespace statemap;

// Static class declarations.
Map1_Start Map1::Start("Map1::Start", 0);
Map1_SName_state Map1::SName_state("Map1::SName_state", 1);
Map1_FoldName_state Map1::FoldName_state("Map1::FoldName_state", 2);
Map1_FileName_state Map1::FileName_state("Map1::FileName_state", 3);
Map1_OK Map1::OK("Map1::OK", 4);

void recognizerClassState::EOS(recognizerClassContext& context)
{
    Default(context);
}

void recognizerClassState::Letter(recognizerClassContext& context, char symb)
{
    Default(context);
}

void recognizerClassState::PointOrUnderline(recognizerClassContext& context, char symb)
{
    Default(context);
}

void recognizerClassState::Slash(recognizerClassContext& context, char symb)
{
    Default(context);
}

void recognizerClassState::Unknown(recognizerClassContext& context)
{
    Default(context);
}

void recognizerClassState::Whitespace(recognizerClassContext& context)
{
    Default(context);
}

void recognizerClassState::Default(recognizerClassContext& context)
{
    throw (
        TransitionUndefinedException(
            context.getState().getName(),
            context.getTransition()));

}

void Map1_Default::Whitespace(recognizerClassContext& context)
{
    recognizerClass& ctxt = context.getOwner();

    recognizerClassState& endState = context.getState();

    context.clearState();
    try
    {
        ctxt.Unacceptable();
        context.setState(endState);
    }
    catch (...)
    {
        context.setState(endState);
        throw;
    }

}

void Map1_Default::Letter(recognizerClassContext& context, char symb)
{
    recognizerClass& ctxt = context.getOwner();

    recognizerClassState& endState = context.getState();

    context.clearState();
    try
    {
        ctxt.Unacceptable();
        context.setState(endState);
    }
    catch (...)
    {
        context.setState(endState);
        throw;
    }

}

void Map1_Default::Slash(recognizerClassContext& context, char symb)
{
    recognizerClass& ctxt = context.getOwner();

    recognizerClassState& endState = context.getState();

    context.clearState();
    try
    {
        ctxt.Unacceptable();
        context.setState(endState);
    }
    catch (...)
    {
        context.setState(endState);
        throw;
    }

}

void Map1_Default::PointOrUnderline(recognizerClassContext& context, char symb)
{
    recognizerClass& ctxt = context.getOwner();

    recognizerClassState& endState = context.getState();

    context.clearState();
    try
    {
        ctxt.Unacceptable();
        context.setState(endState);
    }
    catch (...)
    {
        context.setState(endState);
        throw;
    }

}

void Map1_Default::EOS(recognizerClassContext& context)
{
    recognizerClass& ctxt = context.getOwner();

    recognizerClassState& endState = context.getState();

    context.clearState();
    try
    {
        ctxt.Unacceptable();
        context.setState(endState);
    }
    catch (...)
    {
        context.setState(endState);
        throw;
    }

}

void Map1_Default::Unknown(recognizerClassContext& context)
{
    recognizerClass& ctxt = context.getOwner();

    recognizerClassState& endState = context.getState();

    context.clearState();
    try
    {
        ctxt.Unacceptable();
        context.setState(endState);
    }
    catch (...)
    {
        context.setState(endState);
        throw;
    }

}

void Map1_Start::Letter(recognizerClassContext& context, char symb)
{
    recognizerClass& ctxt = context.getOwner();

    context.getState().Exit(context);
    context.clearState();
    try
    {
        ctxt.addSymb(symb);
        context.setState(Map1::Start);
    }
    catch (...)
    {
        context.setState(Map1::Start);
        throw;
    }
    context.getState().Entry(context);

}

void Map1_Start::Slash(recognizerClassContext& context, char symb)
{
    recognizerClass& ctxt = context.getOwner();

    context.getState().Exit(context);
    context.clearState();
    try
    {
        ctxt.addSymb(symb);
        context.setState(Map1::SName_state);
    }
    catch (...)
    {
        context.setState(Map1::SName_state);
        throw;
    }
    context.getState().Entry(context);

}

void Map1_Start::Whitespace(recognizerClassContext& context)
{

    context.getState().Exit(context);
    context.setState(Map1::Start);
    context.getState().Entry(context);

}

void Map1_SName_state::Letter(recognizerClassContext& context, char symb)
{
    recognizerClass& ctxt = context.getOwner();

    if ((ctxt.serverNameLen()))
    {
        context.getState().Exit(context);
        // No actions.
        context.setState(Map1::SName_state);
        context.getState().Entry(context);
    }
    else
    {
         Map1_Default::Letter(context, symb);
    }

}

void Map1_SName_state::Slash(recognizerClassContext& context, char symb)
{
    recognizerClass& ctxt = context.getOwner();

    if ((ctxt.numberOfSlashes()))
    {
        context.getState().Exit(context);
        context.clearState();
        try
        {
            ctxt.addSymb(symb);
            context.setState(Map1::FoldName_state);
        }
        catch (...)
        {
            context.setState(Map1::FoldName_state);
            throw;
        }
        context.getState().Entry(context);
    }
    else
    {
         Map1_Default::Slash(context, symb);
    }

}

void Map1_FoldName_state::EOS(recognizerClassContext& context)
{
    recognizerClass& ctxt = context.getOwner();

    if ((ctxt.fileNameLen()))
    {
        context.getState().Exit(context);
        context.clearState();
        try
        {
            ctxt.addToTable();
            ctxt.Acceptable();
            context.setState(Map1::OK);
        }
        catch (...)
        {
            context.setState(Map1::OK);
            throw;
        }
        context.getState().Entry(context);
    }
    else
    {
         Map1_Default::EOS(context);
    }

}

void Map1_FoldName_state::Letter(recognizerClassContext& context, char symb)
{
    recognizerClass& ctxt = context.getOwner();

    if ((ctxt.directoryNameLen()))
    {
        context.getState().Exit(context);
        context.clearState();
        try
        {
            ctxt.addSymb(symb);
            context.setState(Map1::FoldName_state);
        }
        catch (...)
        {
            context.setState(Map1::FoldName_state);
            throw;
        }
        context.getState().Entry(context);
    }
    else
    {
         Map1_Default::Letter(context, symb);
    }

}

void Map1_FoldName_state::PointOrUnderline(recognizerClassContext& context, char symb)
{
    recognizerClass& ctxt = context.getOwner();

    if ((ctxt.directoryNameLen()))
    {
        context.getState().Exit(context);
        context.clearState();
        try
        {
            ctxt.addSymb(symb);
            context.setState(Map1::FoldName_state);
        }
        catch (...)
        {
            context.setState(Map1::FoldName_state);
            throw;
        }
        context.getState().Entry(context);
    }
    else
    {
         Map1_Default::PointOrUnderline(context, symb);
    }

}

void Map1_FoldName_state::Slash(recognizerClassContext& context, char symb)
{
    recognizerClass& ctxt = context.getOwner();

    if ((ctxt.numberOfSlashes()))
    {
        context.getState().Exit(context);
        context.clearState();
        try
        {
            ctxt.addSymb(symb);
            context.setState(Map1::FileName_state);
        }
        catch (...)
        {
            context.setState(Map1::FileName_state);
            throw;
        }
        context.getState().Entry(context);
    }
    else
    {
         Map1_Default::Slash(context, symb);
    }

}

void Map1_FileName_state::EOS(recognizerClassContext& context)
{
    recognizerClass& ctxt = context.getOwner();

    if ((ctxt.fileNameLen()))
    {
        context.getState().Exit(context);
        context.clearState();
        try
        {
            ctxt.addToTable();
            ctxt.Acceptable();
            context.setState(Map1::OK);
        }
        catch (...)
        {
            context.setState(Map1::OK);
            throw;
        }
        context.getState().Entry(context);
    }
    else
    {
         Map1_Default::EOS(context);
    }

}

void Map1_FileName_state::Letter(recognizerClassContext& context, char symb)
{
    recognizerClass& ctxt = context.getOwner();

    if ((ctxt.fileNameLen()))
    {
        context.getState().Exit(context);
        context.clearState();
        try
        {
            ctxt.addSymb(symb);
            context.setState(Map1::FileName_state);
        }
        catch (...)
        {
            context.setState(Map1::FileName_state);
            throw;
        }
        context.getState().Entry(context);
    }
    else
    {
         Map1_Default::Letter(context, symb);
    }

}

void Map1_FileName_state::PointOrUnderline(recognizerClassContext& context, char symb)
{
    recognizerClass& ctxt = context.getOwner();

    if ((ctxt.fileNameLen()))
    {
        context.getState().Exit(context);
        context.clearState();
        try
        {
            ctxt.addSymb(symb);
            context.setState(Map1::FileName_state);
        }
        catch (...)
        {
            context.setState(Map1::FileName_state);
            throw;
        }
        context.getState().Entry(context);
    }
    else
    {
         Map1_Default::PointOrUnderline(context, symb);
    }

}

//
// Local variables:
//  buffer-read-only: t
// End:
//
