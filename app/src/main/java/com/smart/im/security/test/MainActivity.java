package com.smart.im.security.test;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import com.smart.im.security.utils.EncryptionUtil;
import com.smart.im.security.utils.VerifyUtil;

import java.util.Random;


public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        final TextView textView = findViewById(R.id.tvMd5);


        textView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
//                String md5 = EncryptionUtil.md5(new Random().nextInt()+"");
//                textView.setText(md5);
                VerifyUtil.signature(MainActivity.this);
            }
        });
    }
}
