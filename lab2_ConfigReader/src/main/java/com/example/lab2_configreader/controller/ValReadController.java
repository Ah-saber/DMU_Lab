package com.example.lab2_configreader.controller;

import com.example.lab2_configreader.entity.Supplier;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.beans.factory.annotation.Value;

@RestController
public class ValReadController {
    @Value("${supplier.scode")
    private String scode;
    @Value("${supplier.spassword")
    private String spassword;
    @Value("${supplier.sname")
    private String sname;

    @RequestMapping("/readval")
    public Supplier readVal() {
        Supplier supplier = new Supplier();
        supplier.setScode(scode);
        supplier.setSpassword(spassword);
        supplier.setSname(sname);
        return supplier;
    }
}
