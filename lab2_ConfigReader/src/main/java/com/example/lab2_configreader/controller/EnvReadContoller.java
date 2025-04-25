package com.example.lab2_configreader.controller;

import com.example.lab2_configreader.entity.Supplier;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.core.env.Environment;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class EnvReadContoller {
    @Autowired
    private Environment environment;

    @RequestMapping("/readenv")
    public Supplier readEnv() {
        Supplier supplier = new Supplier();
        supplier.setScode(environment.getProperty("supplier.scode"));
        supplier.setSname(environment.getProperty("supplier.sname"));
        supplier.setSpassword(environment.getProperty("supplier.spassword"));
        return supplier;
    }
}
