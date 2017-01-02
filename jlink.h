#ifndef JLINK_H
#define JLINK_H
#include <QMainWindow>
#include <QMessageBox>
#include <QLibrary>
#include <QLabel>
#include <QDebug>
#include <QObject>
#include <QTextEdit>
#include <stdint.h>
#include <QException>

/*
 *
 *
*********************************************************************
*
*       API functions

void         JLINKARM_Close(void);
void         JLINKARM_ClrBP(unsigned BPIndex);
void         JLINKARM_ClrError(void);
void         JLINKARM_EnableLog2File(void);
const char * JLINKARM_GetCompileDateTime(void);
U16          JLINKARM_GetEmbeddedFWVersion(void);
void         JLINKARM_GetHWStatus(JTAG_HW_STATUS * pStat);
U32          JLINKARM_GetId(void);
void         JLINKARM_GetIdData(JTAG_ID_DATA * pIdData);
U16          JLINKARM_GetSelDevice(void);
int          JLINKARM_GetVoltage(void);
U16          JLINKARM_GetSpeed(void);
void         JLINKARM_Go(void);
void         JLINKARM_GoIntDis(void);
char         JLINKARM_Halt(void);
char         JLINKARM_HaltNoSave(void);
char         JLINKARM_IsConnected(void);
char         JLINKARM_IsHalted(void);
const char * JLINKARM_Open(void);
int          JLINKARM_ReadDCC(U32 * pData, U32 NumItems, int TimeOut);
void         JLINKARM_ReadDCCFast(U32 * pData, U32 NumItems);
U32          JLINKARM_ReadICEReg(int RegIndex);
int          JLINKARM_ReadMem (U32 addr, U32 count, void * p);
void         JLINKARM_ReadMemU8 (U32 Addr, U32 NumItems, U8 * pData, U8* pStatus);
void         JLINKARM_ReadMemU16(U32 Addr, U32 NumItems, U16* pData, U8* pStatus);
void         JLINKARM_ReadMemU32(U32 Addr, U32 NumItems, U32* pData, U8* pStatus);
U32          JLINKARM_ReadReg (ARM_REG RegIndex);
void         JLINKARM_Reset(void);
void         JLINKARM_ResetPullsTRST (U8 OnOff);
void         JLINKARM_ResetPullsRESET(U8 OnOff);
void         JLINKARM_SelDevice(U16 DeviceIndex);
void         JLINKARM_SetBP(unsigned BPIndex, U32 Addr);
int          JLINKARM_SetEndian(int v);
int          JLINKARM_SetInitRegsOnReset(int v);
void         JLINKARM_SetMaxSpeed(void);
void         JLINKARM_SetResetDelay(int ms);
int          JLINKARM_SetResetPara(int Value);
void         JLINKARM_SetSpeed(int Speed);
char         JLINKARM_Step(void);
int          JLINKARM_Test(void);
U16          JLINKARM_UpdateFirmware(void);
U32          JLINKARM_UpdateFirmwareIfNewer(void);
int          JLINKARM_WaitDCCRead(int TimeOut);
int          JLINKARM_WriteDCC(const U32 * pData, U32 NumItems, int TimeOut);
void         JLINKARM_WriteDCCFast(const U32 * pData, U32 NumItems);
void         JLINKARM_WriteICEReg(int RegIndex, U32 Value, int AllowDelay);
char         JLINKARM_WriteReg(ARM_REG RegIndex, U32 Data);
void         JLINKARM_WriteMem(U32 addr, U32 count, const void * p);
void         JLINKARM_WriteMemDelayed(U32 Addr, U32 Count, const void * p);
void         JLINKARM_WriteU8 (U32 addr, U8 Data);
void         JLINKARM_WriteU16(U32 addr, U16 Data);
void         JLINKARM_WriteU32(U32 addr, U32 Data);

void          JLINKARM_EnableLogCom(void (*DebugFunc)(const char *));


*
 *
 */




typedef void (*void_Func_void_pointer)();
typedef const char *  (*constCharPointer_Func_void_pointer)();
typedef bool (*bool_Func_void_pointer)();
typedef char (*char_Func_void_pointer)();
typedef bool (*void_Func_int_pointer)(int);
typedef uint32_t (*uint32_Func_void_pointer)();
typedef void (*void_Func_uint32_uint32_pByte_pointer)(uint32_t,uint32_t,unsigned char*);
typedef int (*int_Func_uint32_uint32_pByte_pointer)(uint32_t,uint32_t,unsigned char*);
class JLink : public QObject
{
    Q_OBJECT
public:
    QTextEdit *info;
    explicit JLink(QObject *parent = 0);
    ~JLink();
public:
    void appendInfo(QString str){
        if(info){
            info->append(str);
        }
    }
signals:

public slots:
public:
    void_Func_int_pointer JLINKARM_Sleep;
    constCharPointer_Func_void_pointer JLINKARM_Open;
    void_Func_void_pointer JLINKARM_Close;
    void_Func_void_pointer JLINKARM_Reset;
    void_Func_void_pointer JLINKARM_GoAllowSim;
    void_Func_void_pointer JLINKARM_Go;
    char_Func_void_pointer JLINKARM_Halt;
    char_Func_void_pointer JLINKARM_Step;
    void_Func_void_pointer JLINKARM_ClrError;
    void_Func_int_pointer JLINKARM_SetSpeed;
    uint32_Func_void_pointer JLINKARM_GetVoltage;
    int_Func_uint32_uint32_pByte_pointer JLINKARM_ReadMem;
    char_Func_void_pointer JLINKARM_IsConnected;
    int readMem(uint32_t baseAddr,uint32_t size,unsigned char * p){
        if(this->JLINKARM_IsConnected()){
            if(!this->JLINKARM_ReadMem(baseAddr,size,p)){
                appendInfo(tr("success to read %1 bytes from 0x%2 !").arg(size).arg(QString::number(baseAddr,16)));
                return 0;
            }else{
				appendInfo(tr("failed to read %1 bytes from 0x%2 !").arg(size).arg(QString::number(baseAddr,16)));
                return -1;
            }
        }else{
            throw QString(tr("Jlink 已断开"));
        }
    }
};

#endif // JLINK_H
