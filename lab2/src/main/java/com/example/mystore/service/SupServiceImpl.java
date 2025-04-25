package com.example.mystore.service;

import com.example.mystore.core.Result;
import com.example.mystore.entity.Supplier;
import com.example.mystore.repository.SupRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class SupServiceImpl implements SupService {
    @Autowired
    private SupRepository supRepository;

    @Override
    public Result checkSupplier(Supplier supplier) {
        Supplier supObj = supRepository.findSupplier(supplier);
        Result result = new Result();
        if (supObj == null) {
            result.setCode(404);
            result.setMsg("用户不存在！");
        } else {
            if (!supplier.getSpassword().equals(supObj.getSpassword())) {
                result.setCode(403);
                result.setMsg("密码错！");
            } else {
                result.setCode(200);
                result.setMsg("验证通过");
                result.setData(supObj);
            }
        }
        return result;
    }
}
