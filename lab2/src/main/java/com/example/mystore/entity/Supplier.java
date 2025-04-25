package com.example.mystore.entity;

import lombok.Data;

//引入了Lombok框架，不需要增加get/set方法
@Data
public class Supplier {
    private String SCode;
    private String sPassWord;
    private String sName;
    private String sWeiXin;
    private String Tel;
    private Float evaluate;
}
