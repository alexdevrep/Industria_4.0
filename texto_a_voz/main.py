'''
SCRIPT PARA CONVERTIR CUALQUIER TEXTO A VOZ
'''
#Importamos las dependencias necesarias
import gradio as gr
from elevenlabs.client import ElevenLabs
from elevenlabs import VoiceSettings
from dotenv import dotenv_values
from translate import Translator

#Configuración .env
config = dotenv_values(".env")
ELEVENLABS_API_KEY = config["ELEVENLABS_API_KEY"]


#Tomamos el texto de la entrada y lo traducimos a inglés y a español
def texto(text_file,enable_speech):
    try:
        texto=text_file
        en_translation = Translator(
            from_lang="es", to_lang="en").translate(texto)
        #Creamos un botón para deshabilitar los dicursos
        if enable_speech:
            save_file_path = text_to_speach(texto, "es")
            en_save_file_path = text_to_speach(en_translation, "en")
            return save_file_path, en_save_file_path, en_translation
        else:
            return None, None, en_translation
        
    except Exception as e:
        raise gr.Error(f"Se ha producido un error {str(e)}")
    

def text_to_speach(text:str, language: str) -> str:
#Generamos los discursos en ambos idiomas
    try:
        client = ElevenLabs(api_key=ELEVENLABS_API_KEY)

        response = client.text_to_speech.convert(
            voice_id="y6WtESLj18d0diFRruBs",  # Voz en español
            optimize_streaming_latency="0",
            output_format="mp3_22050_32",
            text=text,
            model_id="eleven_multilingual_v2",
            voice_settings=VoiceSettings(
                stability=0.0,
                similarity_boost=0.0,
                style=0.0,
                use_speaker_boost=True,
            ),
        )
#guardamos los archivos de audio
        save_file_path = f"{language}.mp3"

        with open(save_file_path, "wb") as f:
            for chunk in response:
                if chunk:
                    f.write(chunk)

    except Exception as e:
        raise gr.Error(
            f"Se ha producido un error creando el audio: {str(e)}")

    return save_file_path

#Creamos la interfaz web
web = gr.Interface(
    fn=texto,
    inputs=[gr.TextArea(),gr.Checkbox("Enable Speech")],
    outputs=[gr.Audio(label="Spanish",visible=True),
             gr.Audio(label="English", visible=True),
             gr.TextArea(label="Translation",visible="True")],
    title="Convertir texo a voz",
    description="Convertir texo a voz con IA"
)

web.launch()
