class ABase{
        int iMem;
};

class BBase : public virtual ABase {
        int iMem;
};

class CBase : public virtual ABase {
        int iMem;
};

class ABCDerived : public BBase, public CBase {
        int iMem;
};
