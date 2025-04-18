package com.example.mystore.entity;

import lombok.Data;

//引入了Lombok框架，不需要增加get/set方法
@Data
public class Supplier {
    private String scode;
    private String spassword;
    private String sname;
    private String sweixin;
    private String tel;
    private Float evaluate;
}
