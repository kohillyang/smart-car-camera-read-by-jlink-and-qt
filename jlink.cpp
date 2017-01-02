#include "jlink.h"

JLink::JLink(QObject *parent) : QObject(parent)
{
    this->info = new QTextEdit(0);
    QLibrary lib("JLinkARM.dll");
    lib.load();
    if(!lib.isLoaded()){
        QMessageBox::warning(0,"warning","jlink can't be loaded",QMessageBox::Ok,QMessageBox::NoButton);
        exit(1);
    }
    this->JLINKARM_Close =(void_Func_void_pointer)lib.resolve("JLINKARM_Close");
    this->JLINKARM_ClrError = (void_Func_void_pointer)lib.resolve("JLINKARM_ClrError");
    this->JLINKARM_GetVoltage = (uint32_Func_void_pointer)lib.resolve("JLINKARM_GetVoltage");
    this->JLINKARM_Go = (void_Func_void_pointer)lib.resolve("JLINKARM_Go");
    this->JLINKARM_GoAllowSim = (void_Func_void_pointer)lib.resolve("JLINKARM_GoAllowSim");
    this->JLINKARM_Halt = (char_Func_void_pointer)lib.resolve("JLINKARM_Halt");
    this->JLINKARM_Open = (constCharPointer_Func_void_pointer)lib.resolve("JLINKARM_Open");
    this->JLINKARM_ReadMem = (int_Func_uint32_uint32_pByte_pointer)lib.resolve("JLINKARM_ReadMem");
    this->JLINKARM_Reset = (void_Func_void_pointer)lib.resolve("JLINKARM_Reset");
    this->JLINKARM_SetSpeed = (void_Func_int_pointer)lib.resolve("JLINKARM_SetSpeed");
    this->JLINKARM_Sleep = (void_Func_int_pointer)lib.resolve("JLINKARM_Sleep");
    this->JLINKARM_IsConnected = (char_Func_void_pointer)lib.resolve("JLINKARM_IsConnected");
    if(!this->JLINKARM_Open){
        QMessageBox::warning(0,"warning","jlink can't be loaded,\nProgram is exiting ",QMessageBox::Ok,QMessageBox::NoButton);
    }

    const char * infoString = this->JLINKARM_Open();
    this->JLINKARM_SetSpeed(0);
    appendInfo("打开jlink");
    if(this->JLINKARM_IsConnected()){
        this->appendInfo(tr("Jlink has been successfully connected"));
        this->appendInfo(infoString);
    }else{
        QMessageBox::warning(0,"warning",QString("info")+infoString,QMessageBox::Ok,QMessageBox::NoButton);
        exit(1);
    }
    //uint32_t testMem;
    //appendInfo("read four bytes from "+QString::number(this->base_addr,16).toUpper() + ":0x"+QString::number(testMem,16)+"return :"+ QString::number(r,10));
}


JLink::~JLink(){
    if(!this->JLINKARM_Close){
        this->JLINKARM_Close();
    }
    delete info;
}
