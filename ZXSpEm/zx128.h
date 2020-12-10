#ifndef ZX128_H_
#define ZX128_H_
#include "libz80\z80.h"
#include "Z80CPU.h"
class ZXSpectrum128: public ZXSpectrum
{
public:
    ZXSpectrum128(Tape *t);
    virtual ~ZXSpectrum128();
public:
                 virtualvoidinitialise(string romPath) ;
    virtual void            release() ;
    virtual void            resetMachine(bool hard = true) override;
    virtual void            resetToSnapLoad() ;
    virtual void            coreMemoryWrite(uint16_t address, uint8_t data) override;
    virtual uint8_t         coreMemoryRead(uint16_t address) ;
    virtual void            coreMemoryContention(uint16_t address, uint32_t tStates) override;
    virtual uint8_t         coreIORead(uint16_t address) ;
    virtual void            coreIOWrite(uint16_t address, uint8_t data) override;
    virtual uint8_t         coreDebugRead(uint16_t address, void *data) ;
    virtual void            coreDebugWrite(uint16_t address, uint8_t byte, void *data) override;
    static bool             opcodeCallback(uint8_t opcode, uint16_t address, void *param);
    void                    UpdatePort7FFD(uint8_t data);
};
#endif /* ZX128_H_ */
