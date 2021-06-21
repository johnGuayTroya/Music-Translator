/*
 *  @section Esta clase se encarga de abrir el explorador de archivos para que elijamos nuestra pista a traducir
 *   y la guarda en un audio clip para que podamos trabajar con ella
 *  @author J.A.G.T
 *  
 *  Special Thanks to https://www.youtube.com/watch?v=mh5oL3AXEEk
 * 
 */

using System.Collections;
using UnityEngine;
using UnityEditor;
using SmartDLL;

public class SelectMusic : MonoBehaviour
{
   
    public static SelectMusic instance;
    private SmartFileExplorer fileExplorer;

    private string path;
    private AudioSource audioS;
    private AudioClip music;
    public SelectMusic()
    {
        fileExplorer = new SmartFileExplorer();
    }
    //creamos la instancia singelton
    private void Awake()
    {
        if (instance == null)
        {
            instance = this;
        }
        else if (instance != this)
        {
            print("ya existe la instanciaaa");
            Destroy(this);
        }
    }

    private void Start()
    {
        //obtenemos el componente del audio del objeto
        audioS = GetComponent<AudioSource>();
    }

   /// <summary>
   /// Gracias a la Smartdll podemos usar el openFile dialog que podemos encontrar en system.window.Forms
   /// y guardamos la ruta del archivo de sonido 
   /// </summary>
    private void SelectFolderSong()
    {
        string initialDir = @"C:\";
        bool restoreDir   = true;
        string title      = "Select your song";
        string defExt     = "mp3";
        string filter     = "mp3 files (*.mp3)|*.mp3";
        //abrimos
        fileExplorer.OpenExplorer(initialDir, restoreDir, title, defExt, filter);
        //guardamos la ruta
        path = fileExplorer.fileName;
    }
    /// <summary>
    /// metodo para buscar el archivo de texto
    /// </summary>
    public void OpenExplorer()
    {
        //Unity al hacer la build,elimina la clase EditorUtility por eso usamos esta macro
       #if UNITY_EDITOR
        path = EditorUtility.OpenFilePanel("Select a mp3 file", "", "mp3");
       #else
      SelectFolderSong();
       #endif
        //capturamos la pista
        GetSound();
    }

    private void UpdateSound()
    {
        //https://docs.unity3d.com/es/530/ScriptReference/AudioType.html

        WWW webR = new WWW("file:///" + path);
        music = webR.GetAudioClip(true, true, AudioType.MPEG);
        audioS.clip = music;

    }

    /// <summary>
    /// comprobamos que el usuario ha elegido un archivo sino,volvemos a mostrarle el explorador
    /// </summary>
   private void GetSound()
    {
        if (path.Length > 1) { UpdateSound(); }
        else { OpenExplorer(); }
    }

    //BTN METHODS
    public void Play()  {audioS.Play(); StartCoroutine(ShowTime()); }
    public void Pause() {audioS.Pause(); StopAllCoroutines(); }
    public void Stop() { audioS.Stop(); StopAllCoroutines(); }

    /// <summary>
    /// Corrutina que controla el tiempo que llevamos y hace el cambio de segundos a minutos
    /// tambíen actualiza el tiempo de la UI
    /// </summary>
    /// <returns></returns>
   IEnumerator ShowTime()
   {
        while (true)
        {
            DataController.dataCtrlInstance.CurrentSeconds += Time.deltaTime;
            //esto quiere decir que hemos llegado al minuto
            if (DataController.dataCtrlInstance.CurrentSeconds >=60f)
            {
                //actualizamos la UI
                DataController.dataCtrlInstance.CurrentSeconds = 0f;
                DataController.dataCtrlInstance.CurrentMinutes += 1;
            }
            //actualizamos la UI
           DataController.dataCtrlInstance.GetData(0).text = DataController.dataCtrlInstance.CurrentMinutes.ToString();
           DataController.dataCtrlInstance.GetData(1).text = DataController.dataCtrlInstance.CurrentSeconds.ToString();
           
            yield return null;
        }
   }

}
