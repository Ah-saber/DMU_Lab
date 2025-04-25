package com.example.lab2_configreader.entity;

import lombok.Data;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;

@Data
@Component //声明为组件，方便注入
@ConfigurationProperties(prefix = "supplier")  //设置配置文件中key的前缀？借助这个实现自动识别和加载数据
public class Supplier {
    private String scode;
    private String spassword;
    private String sname;
}
