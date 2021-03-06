package jni.yh.com.jnidemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView contentTv = (TextView) findViewById(R.id.tv_content);
        final AndroidJni androidJni = new AndroidJni();
        contentTv.setText(androidJni.getHelloWordText());

        contentTv.setOnClickListener((v) -> {
            Toast.makeText(MainActivity.this, androidJni.setUserName("yh") + "      result：" + androidJni.getResult("23"), Toast.LENGTH_LONG).show();
            androidJni.callMethod();
        });

    }


}
