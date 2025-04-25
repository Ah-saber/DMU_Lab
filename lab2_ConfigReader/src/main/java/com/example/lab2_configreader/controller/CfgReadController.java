package com.example.lab2_configreader.controller;

import com.example.lab2_configreader.entity.Supplier;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class CfgReadController {
    @Autowired
    Supplier supplier;

    @RequestMapping("/readcfg")
    public Supplier readCfg() {
        return supplier;  //直接返回显示
    }
}
