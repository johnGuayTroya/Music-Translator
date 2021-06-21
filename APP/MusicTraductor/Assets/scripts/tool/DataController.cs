
/*
 * @section 
 * En esta clase declaramos al final los métodos importados de la dll
 * A su vez creamos varibales para introducir en nuestro map de secuencias
 * y están implementados los métodos de los botones que tendrá nuestra herramienta
 *  @author J.A.G.T
 * 
 * 
 */

using UnityEngine;
using UnityEngine.UI;
using System;
using System.Runtime.InteropServices;

public class DataController : MonoBehaviour
{

#if UNITY_IPHONE
        const string DllName = "__Internal";
#else
    const string DllName = "UnityTool";   //ponemos el nombre de la dll que se encuentre en el proyecto
#endif

    //DLL var
    private UIntPtr instance;
 
    //FRONTEND VARS
    public Text txtInfo;                 //TextContainer
    public InputField []data;  // 0->min 1->seg 2->text
    public static DataController dataCtrlInstance;

    private int secuence;
    private int currentMinutes;
    private float currentSeconds;
    
    //creamos la instancia singelton
    private void Awake()
    {
        if (dataCtrlInstance == null)
        {
            dataCtrlInstance = this;
        }
        else if (dataCtrlInstance != this)
        {
            print("ya existe la instanciaaa");
            Destroy(this);
        }
    }

    //Constructor
    public DataController()
    {
        instance = DataControllerConstructor();
        secuence = 1;
        currentSeconds = 0;
        currentMinutes = 0;
    }

    //Propiedades
    public float CurrentSeconds   
    {
        get { return currentSeconds; }   
        set { currentSeconds = value; }  
    }
    public int CurrentMinutes
    {
        get { return currentMinutes; }
        set { currentMinutes = value; }
    }

    #region Métodos
    /// <summary>
    /// Reiniciamos la UI
    /// </summary>
    private void ResetUi()
    {
        CurrentSeconds = 0;
        CurrentMinutes = 0;
        secuence = 1;
        //SelectMusic.instance.Stop();
        ClearTxt();
    }
    private void ClearTxt()
    {
        //limpiamos el texto del container
        txtInfo.text = "";
        //limpiamos los textos de los inputFields
        foreach (InputField input in this.data)
        {
            input.text = "";
        }
     }
    /// <summary>
    ///  cogemos los datos del inputfield que necesitemos
    /// </summary>
    public InputField GetData(byte id)
    {
        if(id >= 0 && id< data.Length)
        {
            return data[id];
        }

        return null;
    }

#endregion

    #region Métodos de los botones
    /// <summary>
    /// Convertimos los datos de los inputs a valores que nuestro map acepta
    /// y añadmos los datos
    /// </summary>
    public void Add()
    {
        if (AddSecuence(instance, secuence, currentMinutes, currentSeconds, data[2].text))
        {
            //actualizamos el progreso de la cancion 
            txtInfo.text += data[2].text + "\n";
            //borramos el inputText
            data[2].text = "";
            //pasamos a la siguieten secuencia
            secuence++;
        }

    }
    public void SaveFile()
    {
        SaveData(instance);
    }
    public void SaveSerializeFile()
    {
        SaveSerializeData(instance);
    }
    public void Deserialize()
    {
        DeserializeData(instance);
    }
    public void ResetEditor()
    {
        //eliminamos la informacion del  map
        Reset(instance);
        //reseteamos la UI
        ResetUi();
        //Volvemos al inicio de nuestra pista
        SelectMusic.instance.Stop();
    }

    #endregion

    #region METODOS DLLIMPORT 
    [DllImport(DllName)] private static extern UIntPtr DataControllerConstructor();
    [DllImport(DllName)] private static extern bool SaveData(UIntPtr instance);
    [DllImport(DllName)] private static extern bool AddSecuence(UIntPtr instance, int secuence, int min, float s, string text);
    [DllImport(DllName)] private static extern bool SaveSerializeData(UIntPtr instance);
    [DllImport(DllName)] private static extern bool DeserializeData(UIntPtr instance);
    [DllImport(DllName)] private static extern bool Reset(UIntPtr instance);

    #endregion
}
