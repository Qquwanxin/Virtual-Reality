using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class All : MonoBehaviour
{
    // Start is called before the first frame update
    public float timer;
    public static Text txt;	
    public static Text txt1;	
	public static float x = 0;
    public int totalCount;
    void Start()
    {
        timer = 30.0f;
        Debug.Log("START");
        txt = GameObject.Find ("Text").GetComponent<Text> ();
        txt1 = GameObject.Find ("Text (1)").GetComponent<Text> ();
        totalCount=0;
    }

    // Update is called once per frame
    void Update()
    {
        timer -= Time.deltaTime;
        totalCount = box1.count + box2.count + box3.count + box4.count;
        All.txt.text = "Score : " + totalCount+"\nTime : "+ timer.ToString("#0.00") + " s";
        
        if(Input.GetKeyDown(KeyCode.Escape)){
            #if UNITY_EDITOR
                UnityEditor.EditorApplication.isPlaying = false;
            #else
                Application.Quit();
            #endif
        }

        if(timer <= 0){
            GameObject.Find("Main Camera").GetComponent<MouseLook>().enabled=false;
            GameObject.Find("Main Camera").GetComponent<cameraControl>().enabled=false;
            GameObject.Find("GameObject").GetComponent<LightSwitch>().enabled=false;
            GameObject.Find("GameObject").GetComponent<box1>().enabled=false;
            GameObject.Find("GameObject (1)").GetComponent<box2>().enabled=false;
            GameObject.Find("GameObject (2)").GetComponent<box3>().enabled=false;
            GameObject.Find("GameObject (3)").GetComponent<box4>().enabled=false;
            
            All.txt.text =" ";
            All.txt1.text = "GAME OVER\n" + "<color=black>Score : " + totalCount+"</color>";
        }
        
       
    }
}
